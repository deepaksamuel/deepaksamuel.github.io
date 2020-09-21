# this will create the webpage elements for gold medalists and PhD grads
#%%
import numpy as np
import pandas as pd

df = pd.read_excel ('goldmedalists.xlsx')

for i in range(39):
    print('<center> <div class="card">')
    
    print('<img src=') 
    
    print('"')
    print('img/gm/f ('+ str(i+1) +').png')
    print('"')
    print('alt="Avatar" style="width:25%">')
    
    print('<div class="container">')
    print('<h4><b>')

    print(df['Name of the Rank Holder'][i])

   
    print('</b></h4>')
    print('<p>')
    print(df['Enrolment Number'][i])
    print("|")
    print(df['Progarmme'][i])
    print('</p>') 
    
    print('</div> </div> <br>')

#%%