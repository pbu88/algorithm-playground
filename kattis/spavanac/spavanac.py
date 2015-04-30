from datetime import datetime, timedelta
h, m = map(int, raw_input().split(' '))
dt = datetime(2015,1,1,hour=h, minute=m)
td = dt - timedelta(minutes=45)
print td.hour, td.minute
