class Days(object):

    monthsDict = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31,\
                  11:30, 12:31}

    def __init__(self, startdate, enddate):
        startdateArr = startdate.split("/")
        self.startmonth = startdateArr[0]
        self.startday = startdateArr[1]
        self.startyear = startdateArr[2]
        enddateArr = enddate.split("/")
        self.endmonth = enddateArr[0]
        self.endday = enddateArr[1]
        self.endyear = enddateArr[2]

    def febAdd(self, year):
        if int(year)%4 == 0:
            return 1
        else:
            return 0

    def yearsCalc(self):
        yearsShare = 0
        for i in range((int(self.startyear)+1), int(self.endyear)):
            lamb = lambda x : 365 if x%4 != 0 else 365
            yearsShare += lamb(i)
            print "in for years",lamb(i) 
        print "years share", yearsShare 
        return yearsShare

    def monthsCalc(self):
        daysFromMonth = 0
        """ 
        if its from the same year, we should add only the difference months
        """
        if self.startyear == self.endyear:
            for i in range(int(self.startmonth)+1, int(self.endmonth)):
                print "adding month", Days.monthsDict[i]
                daysFromMonth += Days.monthsDict[i]
                if i == 2:
                    daysFromMonth += self.febAdd(self.startyear)
            return daysFromMonth

        """ 
        from next month to december the number days from months are added
        """ 
        for i in range(int(self.startmonth)+1, 13):
            print "adding start month", Days.monthsDict[i]
            daysFromMonth += Days.monthsDict[i]
            if i == 2:
                print "adding feb share start", self.febAdd(self.startyear)
                daysFromMonth += self.febAdd(self.endyear)

        print "month share 1", daysFromMonth 
        """ 
        from jan to month before end month, number of days from months are added
        """ 
        for i in range(1, int(self.endmonth)):
            print "adding end month %d" %i, Days.monthsDict[i]
            daysFromMonth += Days.monthsDict[i]
            if i == 2:
                print "adding feb share end", self.febAdd(self.endyear)
                daysFromMonth += self.febAdd(self.endyear)

        print "month share", daysFromMonth 
        return daysFromMonth

    def daysCalc(self):
        daysShare = Days.monthsDict[int(self.startmonth)] - int(self.startday) + 1 +\
                    self.febAdd(self.startyear) + int(self.endday)
        print "days share", daysShare
        return daysShare

    def daysDiff(self):
        return self.daysCalc() + self.monthsCalc() + self.yearsCalc()

test = Days("1/15/14", "3/19/16")
print test.daysDiff()
