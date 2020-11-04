# this will create the webpage elements for gold medalists and PhD grads
#%%
import numpy as np
import pandas as pd

df = pd.read_excel ('phd.xlsx')

for i in range(25):
    print('<center> <div class="card">')
    
    print('<img src=') 
    
    print('"')
    print('img/phd/f ('+ str(i+1) +').png')
    print('"')
    print('alt="Avatar" style="width:25%">')
    
    print('<div class="container">')
    print('<h4><b>')

    print(df['NAME OF THE CANDIDATE'][i])

   
    print('</b></h4>')
    print('<p>')
    print(df['SCHOOL'][i])
    print("|")
    print(df['SUBJECT'][i])
    print('</p>') 
    
    print('</div> </div> <br>')

#%%