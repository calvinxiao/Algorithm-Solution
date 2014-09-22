/*
#Problem ID: 2949
#Submit Time: 2013-11-08 16:44:19
#Run Time: 0
#Run Memory: 176
#ZOJ User: calvinxiao
*/

#include <cstdio>
using namespace std;

double f[] = {0.0, 1.0, 2.5, 4.12, 5.81, 7.54, 9.29, 11.07, 12.86, 14.66, 16.48, 18.3, 20.13, 21.97, 23.82, 25.67, 27.52, 29.38, 31.25, 33.11, 34.99, 36.86, 38.74, 40.62, 42.5, 44.39, 46.27, 48.16, 50.06, 51.95, 53.85, 55.74, 57.64, 59.54, 61.44, 63.35, 65.25, 67.16, 69.07, 70.98, 72.89, 74.8, 76.71, 78.62, 80.54, 82.45, 84.37, 86.28, 88.2, 90.12, 92.04, 93.96, 95.88, 97.8, 99.73, 101.65, 103.57, 105.5, 107.43, 109.35, 111.28, 113.21, 115.13, 117.06, 118.99, 120.92, 122.85, 124.78, 126.71, 128.64, 130.58, 132.51, 134.44, 136.38, 138.31, 140.24, 142.18, 144.11, 146.05, 147.99, 149.92, 151.86, 153.8, 155.74, 157.67, 159.61, 161.55, 163.49, 165.43, 167.37, 169.31, 171.25, 173.19, 175.13, 177.07, 179.02, 180.96, 182.9, 184.84, 186.79, 188.73, 190.67, 192.62, 194.56, 196.51, 198.45, 200.4, 202.34, 204.29, 206.23, 208.18, 210.13, 212.07, 214.02, 215.97, 217.91, 219.86, 221.81, 223.76, 225.7, 227.65, 229.6, 231.55, 233.5, 235.45, 237.4, 239.35, 241.3, 243.25, 245.2, 247.15, 249.1, 251.05, 253.0, 254.95, 256.9, 258.85, 260.8, 262.76, 264.71, 266.66, 268.61, 270.57, 272.52, 274.47, 276.42, 278.38, 280.33, 282.28, 284.24, 286.19, 288.15, 290.1, 292.05, 294.01, 295.96, 297.92, 299.87, 301.83, 303.78, 305.74, 307.69, 309.65, 311.6, 313.56, 315.52, 317.47, 319.43, 321.39, 323.34, 325.3, 327.26, 329.21, 331.17, 333.13, 335.08, 337.04, 339.0, 340.96, 342.91, 344.87, 346.83, 348.79, 350.75, 352.7, 354.66, 356.62, 358.58, 360.54, 362.5, 364.46, 366.42, 368.37, 370.33, 372.29, 374.25, 376.21, 378.17, 380.13, 382.09, 384.05, 386.01, 387.97, 389.93, 391.89, 393.85, 395.81, 397.78, 399.74, 401.7, 403.66, 405.62, 407.58, 409.54, 411.5, 413.46, 415.43, 417.39, 419.35, 421.31, 423.27, 425.23, 427.2, 429.16, 431.12, 433.08, 435.05, 437.01, 438.97, 440.93, 442.9, 444.86, 446.82, 448.79, 450.75, 452.71, 454.67, 456.64, 458.6, 460.56, 462.53, 464.49, 466.46, 468.42, 470.38, 472.35, 474.31, 476.28, 478.24, 480.2, 482.17, 484.13, 486.1, 488.06, 490.03, 491.99, 493.95, 495.92, 497.88, 499.85, 501.81, 503.78, 505.74, 507.71, 509.67, 511.64, 513.61, 515.57, 517.54, 519.5, 521.47, 523.43, 525.4, 527.36, 529.33, 531.3, 533.26, 535.23, 537.19, 539.16, 541.13, 543.09, 545.06, 547.03, 548.99, 550.96, 552.93, 554.89, 556.86, 558.83, 560.79, 562.76, 564.73, 566.69, 568.66, 570.63, 572.59, 574.56, 576.53, 578.5, 580.46, 582.43, 584.4, 586.37, 588.33, 590.3, 592.27, 594.24, 596.21, 598.17, 600.14, 602.11, 604.08, 606.04, 608.01, 609.98, 611.95, 613.92, 615.89, 617.85, 619.82, 621.79, 623.76, 625.73, 627.7, 629.67, 631.63, 633.6, 635.57, 637.54, 639.51, 641.48, 643.45, 645.42, 647.39, 649.35, 651.32, 653.29, 655.26, 657.23, 659.2, 661.17, 663.14, 665.11, 667.08, 669.05, 671.02, 672.99, 674.96, 676.93, 678.9, 680.87, 682.84, 684.81, 686.78, 688.75, 690.72, 692.69, 694.66, 696.63, 698.6, 700.57, 702.54, 704.51, 706.48, 708.45, 710.42, 712.39, 714.36, 716.33, 718.3, 720.27, 722.24, 724.21, 726.19, 728.16, 730.13, 732.1, 734.07, 736.04, 738.01, 739.98, 741.95, 743.92, 745.9, 747.87, 749.84, 751.81, 753.78, 755.75, 757.72, 759.69, 761.67, 763.64, 765.61, 767.58, 769.55, 771.52, 773.5, 775.47, 777.44, 779.41, 781.38, 783.35, 785.33, 787.3, 789.27, 791.24, 793.21, 795.19, 797.16, 799.13, 801.1, 803.08, 805.05, 807.02, 808.99, 810.96, 812.94, 814.91, 816.88, 818.85, 820.83, 822.8, 824.77, 826.74, 828.72, 830.69, 832.66, 834.64, 836.61, 838.58, 840.55, 842.53, 844.5, 846.47, 848.45, 850.42, 852.39, 854.36, 856.34, 858.31, 860.28, 862.26, 864.23, 866.2, 868.18, 870.15, 872.12, 874.1, 876.07, 878.04, 880.02, 881.99, 883.96, 885.94, 887.91, 889.88, 891.86, 893.83, 895.81, 897.78, 899.75, 901.73, 903.7, 905.67, 907.65, 909.62, 911.6, 913.57, 915.54, 917.52, 919.49, 921.47, 923.44, 925.41, 927.39, 929.36, 931.34, 933.31, 935.28, 937.26, 939.23, 941.21, 943.18, 945.16, 947.13, 949.11, 951.08, 953.05, 955.03, 957.0, 958.98, 960.95, 962.93, 964.9, 966.88, 968.85, 970.83, 972.8, 974.77, 976.75, 978.72, 980.7, 982.67, 984.65, 986.62, 988.6, 990.57, 992.55, 994.52, 996.5, 998.47, 1000.45, 1002.42, 1004.4, 1006.37, 1008.35, 1010.32, 1012.3, 1014.28, 1016.25, 1018.23, 1020.2, 1022.18, 1024.15, 1026.13, 1028.1, 1030.08, 1032.05, 1034.03, 1036.0, 1037.98, 1039.96, 1041.93, 1043.91, 1045.88, 1047.86, 1049.83, 1051.81, 1053.78, 1055.76, 1057.74, 1059.71, 1061.69, 1063.66, 1065.64, 1067.62, 1069.59, 1071.57, 1073.54, 1075.52, 1077.5, 1079.47, 1081.45, 1083.42, 1085.4, 1087.38, 1089.35, 1091.33, 1093.3, 1095.28, 1097.26, 1099.23, 1101.21, 1103.18, 1105.16, 1107.14, 1109.11, 1111.09, 1113.07, 1115.04, 1117.02, 1119.0, 1120.97, 1122.95, 1124.92, 1126.9, 1128.88, 1130.85, 1132.83, 1134.81, 1136.78, 1138.76, 1140.74, 1142.71, 1144.69, 1146.67, 1148.64, 1150.62, 1152.6, 1154.57, 1156.55, 1158.53, 1160.5, 1162.48, 1164.46, 1166.44, 1168.41, 1170.39, 1172.37, 1174.34, 1176.32, 1178.3, 1180.27, 1182.25, 1184.23, 1186.21, 1188.18, 1190.16, 1192.14, 1194.11, 1196.09, 1198.07, 1200.05, 1202.02, 1204.0, 1205.98, 1207.95, 1209.93, 1211.91, 1213.89, 1215.86, 1217.84, 1219.82, 1221.8, 1223.77, 1225.75, 1227.73, 1229.71, 1231.68, 1233.66, 1235.64, 1237.62, 1239.59, 1241.57, 1243.55, 1245.53, 1247.5, 1249.48, 1251.46, 1253.44, 1255.42, 1257.39, 1259.37, 1261.35, 1263.33, 1265.3, 1267.28, 1269.26, 1271.24, 1273.22, 1275.19, 1277.17, 1279.15, 1281.13, 1283.1, 1285.08, 1287.06, 1289.04, 1291.02, 1292.99, 1294.97, 1296.95, 1298.93, 1300.91, 1302.89, 1304.86, 1306.84, 1308.82, 1310.8, 1312.78, 1314.75, 1316.73, 1318.71, 1320.69, 1322.67, 1324.65, 1326.62, 1328.6, 1330.58, 1332.56, 1334.54, 1336.52, 1338.49, 1340.47, 1342.45, 1344.43, 1346.41, 1348.39, 1350.37, 1352.34, 1354.32, 1356.3, 1358.28, 1360.26, 1362.24, 1364.22, 1366.19, 1368.17, 1370.15, 1372.13, 1374.11, 1376.09, 1378.07, 1380.04, 1382.02, 1384.0, 1385.98, 1387.96, 1389.94, 1391.92, 1393.9, 1395.88, 1397.85, 1399.83, 1401.81, 1403.79, 1405.77, 1407.75, 1409.73, 1411.71, 1413.69, 1415.66, 1417.64, 1419.62, 1421.6, 1423.58, 1425.56, 1427.54, 1429.52, 1431.5, 1433.48, 1435.46, 1437.43, 1439.41, 1441.39, 1443.37, 1445.35, 1447.33, 1449.31, 1451.29, 1453.27, 1455.25, 1457.23, 1459.21, 1461.19, 1463.17, 1465.14, 1467.12, 1469.1, 1471.08, 1473.06, 1475.04, 1477.02, 1479.0, 1480.98, 1482.96, 1484.94, 1486.92, 1488.9, 1490.88, 1492.86, 1494.84, 1496.82, 1498.8, 1500.78, 1502.75, 1504.73, 1506.71, 1508.69, 1510.67, 1512.65, 1514.63, 1516.61, 1518.59, 1520.57, 1522.55, 1524.53, 1526.51, 1528.49, 1530.47, 1532.45, 1534.43, 1536.41, 1538.39, 1540.37, 1542.35, 1544.33, 1546.31, 1548.29, 1550.27, 1552.25, 1554.23, 1556.21, 1558.19, 1560.17, 1562.15, 1564.13, 1566.11, 1568.09, 1570.07, 1572.05, 1574.03, 1576.01, 1577.99, 1579.97, 1581.95, 1583.93, 1585.91, 1587.89, 1589.87, 1591.85, 1593.83, 1595.81, 1597.79, 1599.77, 1601.75, 1603.73, 1605.71, 1607.69, 1609.67, 1611.65, 1613.63, 1615.61, 1617.59, 1619.58, 1621.56, 1623.54, 1625.52, 1627.5, 1629.48, 1631.46, 1633.44, 1635.42, 1637.4, 1639.38, 1641.36, 1643.34, 1645.32, 1647.3, 1649.28, 1651.26, 1653.24, 1655.22, 1657.2, 1659.18, 1661.17, 1663.15, 1665.13, 1667.11, 1669.09, 1671.07, 1673.05, 1675.03, 1677.01, 1678.99, 1680.97, 1682.95, 1684.93, 1686.91, 1688.9, 1690.88, 1692.86, 1694.84, 1696.82, 1698.8, 1700.78, 1702.76, 1704.74, 1706.72, 1708.7, 1710.68, 1712.67, 1714.65, 1716.63, 1718.61, 1720.59, 1722.57, 1724.55, 1726.53, 1728.51, 1730.49, 1732.47, 1734.46, 1736.44, 1738.42, 1740.4, 1742.38, 1744.36, 1746.34, 1748.32, 1750.3, 1752.29, 1754.27, 1756.25, 1758.23, 1760.21, 1762.19, 1764.17, 1766.15, 1768.13, 1770.12, 1772.1, 1774.08, 1776.06, 1778.04, 1780.02, 1782.0, 1783.98, 1785.97, 1787.95, 1789.93, 1791.91, 1793.89, 1795.87, 1797.85, 1799.84, 1801.82, 1803.8, 1805.78, 1807.76, 1809.74, 1811.72, 1813.7, 1815.69, 1817.67, 1819.65, 1821.63, 1823.61, 1825.59, 1827.58, 1829.56, 1831.54, 1833.52, 1835.5, 1837.48, 1839.46, 1841.45, 1843.43, 1845.41, 1847.39, 1849.37, 1851.35, 1853.34, 1855.32, 1857.3, 1859.28, 1861.26, 1863.24, 1865.23, 1867.21, 1869.19, 1871.17, 1873.15, 1875.13, 1877.12, 1879.1, 1881.08, 1883.06, 1885.04, 1887.02, 1889.01, 1890.99, 1892.97, 1894.95, 1896.93, 1898.92, 1900.9, 1902.88, 1904.86, 1906.84, 1908.83, 1910.81, 1912.79, 1914.77, 1916.75, 1918.73, 1920.72, 1922.7, 1924.68, 1926.66, 1928.64, 1930.63, 1932.61, 1934.59, 1936.57, 1938.55, 1940.54, 1942.52, 1944.5, 1946.48, 1948.47, 1950.45, 1952.43, 1954.41, 1956.39, 1958.38, 1960.36, 1962.34, 1964.32};
int main()
{
  int tc, n;
  scanf("%d", &tc);
  while (tc--) {
    scanf("%d", &n);
    printf("%.2lf\n", f[n]);
  }
	return 0;
}
