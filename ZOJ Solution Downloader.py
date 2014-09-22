import urllib, urllib2, cookielib
from bs4 import BeautifulSoup

username = ''
password = ''
startpage = 'http://acm.zju.edu.cn/onlinejudge/showRuns.do?contestId=1&search=true'
startpage += '&firstId=-1&lastId=%d&problemCode=&handle=' + username 
startpage += '&idStart=&idEnd=&judgeReplyIds=5'
fileNames = set([]) #download the latest solution only

def process(html, opener, fileNames):
	soup = BeautifulSoup(html)
	runId = None
	for table in soup.find_all('table', class_='list'):
		trs = table.find_all('tr')
		rowindex = 0
		for tr in trs:
			rowindex += 1
			if rowindex == 1:
				continue
			runId = int(str(tr.find(class_='runId').string))
			runSubmitTime = tr.find(class_='runSubmitTime').string
			runJudgeStatus = tr.find(class_='runJudgeStatus').string
			runProblemId = tr.find(class_='runProblemId').string
			runLanguage = tr.find(class_='runLanguage').find('a')
			runTime = tr.find(class_='runTime').string
			runMemory = tr.find(class_='runMemory').string
			runUserName = tr.find(class_='runUserName').string
			
			languageType = runLanguage.string
			
			if languageType in ['C', 'C++', 'Python']:
				comment=  '/*\n%s\n*/'
				ext = '.c'
				if languageType == 'C++':
					ext = '.cpp'
				elif languageType == 'Python':
					ext = '.py'
					comment = '%s'

				fileName = runProblemId + ext
				if fileName in fileNames:
					continue
				fileNames.add(fileName)

				lst = []
				lst.append('#Problem ID: %s' % runProblemId)
				lst.append('#Submit Time: %s' % runSubmitTime)
				lst.append('#Run Time: %s' % runTime)
				lst.append('#Run Memory: %s' % runMemory)
				lst.append('#ZOJ User: %s' % runUserName)
				comment = comment % '\n'.join(lst)
				sourcecode = opener.open('http://acm.zju.edu.cn'+ runLanguage.get('href')).read()
				
				with open(fileName, 'w') as f:
					f.write(comment)
					f.write('\n\n')
					f.write(sourcecode)
					print '%s is succefully created' % fileName
				
	return runId




cj = cookielib.CookieJar()
opener = urllib2.build_opener(urllib2.HTTPCookieProcessor(cj))
login_data = urllib.urlencode({'handle' : username, 'password' : password})
opener.open('http://acm.zju.edu.cn/onlinejudge/login.do', login_data)
lastid = -1
resp = opener.open(startpage % lastid)
while 1:
	newLastId = process( resp.read(), opener, fileNames)
	if newLastId is None:
		break
	lastid = newLastId
	resp = opener.open(startpage % lastid)

