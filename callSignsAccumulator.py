import shutil, os
import StringIO
from pyspark import SparkConf, SparkContext


conf = SparkConf().setMaster("local").setAppName("callSignAccumulator")
sc = SparkContext(conf = conf)

lines = sc.textFile("Employees.csv")

# Create Accumulator[int] initialized to 0
blankLines = sc.accumulator(0)

def extractCallSigns(line):
    global blankLines
    if (line == ""):
        blankLines += 1
    return line.split(" ")

callSigns = lines.flatMap(extractCallSigns)
# se esiste la cartella che contiene i file di output viene eliminata, non faccio niente altrimenti.
if os.path.exists("outputDirs"):
    shutil.rmtree("outputDirs")
callSigns.saveAsTextFile("outputDirs" + "/callSigns")
print "Blank lines: %d" % blankLines.value
