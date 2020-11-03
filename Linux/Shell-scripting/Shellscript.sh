#!/bin/bash
OLDIFS=$IFS
touch makeop.csv
mydirectory="$(pwd)"
echo "UserName,EmailId,Repository link,Git- clone status,Build-status,valgrind,cppcheck" >>"$mydirectory"/Results.csv
while IFS="," read  Name EmailID Repolink; do 
	
	echo "$Name$EmailID $Repolink" 
	
	git clone $Repolink >>"$mydirectory"/gitclone.txt
	if [ $? -eq 0 ];then
  		echo -n "$Name,$EmailID,$Repolink,success," >>"$mydirectory"/Results.csv
  		
 	else 
 		echo -n "$Name,$EmailID,$Repolink,Fail," >>"$mydirectory"/Results.csv
	fi
	
	
	myrepo="$(cut -d"/" -f5 <<<"$Repolink")"
	myrepofull="$(cut -d"." -f1 <<<"$myrepo")"
	echo "my pwd is: $mydirectory" 
	echo "my repository is :$myrepofull"
	cd "$mydirectory"/"$myrepofull"
	
	make >> "$mydirectory"/make.txt
	
	if [ $? -eq 0 ]; then
  		echo  -n "Build Success," >>"$mydirectory"/Results.csv
  		
 	else 
 		echo -n "Build Failed," >>"$mydirectory"/Results.csv
	fi
	
	
	
	valgrind ./*.out >"$mydirectory"/valgrind.txt 2>&1
          
       lastline="$( tail -n 1 "$mydirectory"/valgrind.txt)"
       errors="$(cut -d" " -f4 <<<"$lastline")"
       echo -n "$errors," >>"$mydirectory"/Results.csv
       
       cppcheck *.c* >"$mydirectory"/cppreport.txt 2>&1
       #cppcheck *.cpp >"$mydirectory"/cppreport.txt 2>&1
       
       echo "$(grep -o 'error' "$mydirectory"/cppreport.txt| wc -l)" >>"$mydirectory"/Results.csv
       
       
     
	
	
	cd "$mydirectory" 
 	IFS=$OLDFIS
 	
done<$1

 
 
 
 
 
#link2 - https://github.com/99002548/demo_shell1.git
#link1="https://github.com/99002548/Checkrepo.git"
#User1,User1@user.com,https://github.com/99002548/Checkrepo.git
