import sys
import subprocess

args=sys.argv

if len(args)<=1:
    print("引数が足りません")
else:
    score_sum=0
    subprocess.run(f'g++ -std=c++17 {args[1]}',shell=True)
    for i in range(100):
        cp=subprocess.run(f"cargo run -r --bin tester ./a.out < in/{str(i).zfill(4)}.txt > out.txt",shell=True,capture_output=True,text=True)
        str_list=cp.stderr.split()
        print(i,str_list[-1])
        score_sum+=int(str_list[-1])
    print(score_sum/100)


