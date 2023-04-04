@echo off
@echo;
@echo Running ExternalSort 5 Times...

perl ExternalSort.pl data5K.txt sorted5K.txt 100
perl ExternalSort.pl data40K.txt sorted40K.txt 1000
perl ExternalSort.pl data300K.txt sorted300K.txt 10000
perl ExternalSort.pl data2M.txt sorted2M.txt 100000
perl ExternalSort.pl data10M.txt sorted10M.txt 200000

@echo 5 Runs Completed
@echo;
pause
