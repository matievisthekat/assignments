@echo off
@echo;
@echo Running CreateBigData 5 Times...

perl CreateBigData.pl data5K.txt 5000
perl CreateBigData.pl data40K.txt 40000
perl CreateBigData.pl data300K.txt 300000
perl CreateBigData.pl data2M.txt 2000000
perl CreateBigData.pl data10M.txt 10000000

@echo 5 Runs Completed
@echo;
pause
