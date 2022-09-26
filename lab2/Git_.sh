echo -n "Какой файл запушить? : "; ACT1=$(head -1)
echo -n "В какую лабу? : "; ACT2=$(head -1)
mv $ACT1 ~/GitRepos/$ACT2/
cd ~/GitRepos/$ACT2/
git add $ACT1
echo -n "Кокое сообщение коммита? : "; ACT1=$(head -1)
git commit -m "$ACT1"
git push
