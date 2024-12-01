import pandas as pd

f=pd.read_excel("../Nanj_BusExcel.xlsx")

ct=f.to_dict(orient='dict')

with open("../BusMap.txt","w",encoding="utf-8") as filet:
    # 按行遍历表格数据
    t = 0
    for _, row in f.iterrows():
        for column, value in row.items():
            if(t==1):
                filet.write(f"{value} ")
            if(t==4):
                filet.write(f"{value}\n")
            t+=1
        t=0

with open("../RoadMap.txt","w",encoding="utf-8") as filet:
    # 按行遍历表格数据
    t = 0
    st=""
    for _, row in f.iterrows():
        for column, value in row.items():
            if(st==value):
                break
            if(t==0):
                filet.write(f"{value} ")
                st=value
            if(t==2):
                filet.write(f"{value}\n")
            t+=1
        t=0





