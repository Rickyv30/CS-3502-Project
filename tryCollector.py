
from collector import Collector

c1 = Collector()
c1.add(5)
c1.add(51)
c1.add(25)
c1.add(45)
c1.add(25)
c1.add(52)

print ("This is the count", c1.count())
print ("This is the sum of the squares", c1.sum_squares())
print ("This is the standard deviation", c1.standard_deviation())
print ("This is the variance", c1.variance())
print ("This is the average", c1.average())

