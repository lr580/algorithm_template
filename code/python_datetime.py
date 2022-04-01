from datetime import *
d1, d2 = datetime(2022,5,8), datetime(2002,5,8)
print((d1-d2).days) # 天数差
print((datetime.today()+timedelta(days=1)).weekday()) #星期[0,6]一-日