import time
import datetime
class Solution:
    def daysBetweenDates(self, date1: str, date2: str) -> int:
        date1=time.strptime(date1,"%Y-%m-%d")
        date2=time.strptime(date2,"%Y-%m-%d")
        date1=datetime.datetime(date1[0],date1[1],date1[2])
        date2=datetime.datetime(date2[0],date2[1],date2[2])

        return abs((date2-date1).days)