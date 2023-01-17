#!/usr/bin/env python
# coding: utf-8

# In[6]:


import pandas as pd
data_RR1 = pd.read_csv('C:/Users/DHARAM/Downloads/Round_Robin_1ms.csv')


# In[8]:


data_RR1


# In[42]:


data_RR2 = pd.read_csv('C:/Users/DHARAM/Downloads/Round_Robin_2ms.csv')
data_RR2


# In[9]:


import matplotlib.pyplot as plt


# In[41]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P1_RR1.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[1])
  
plt.plot(x, y, color = 'r', linestyle = 'dashed',
         marker = 'o',label = "Wait Time Data for TQ = 1ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Wait Time')
plt.title('Wait Time Data for TQ = 1ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[40]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P1_RR1.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[2])
  
plt.plot(x, y, color = 'r', linestyle = 'dashed',
         marker = 'o',label = "Burst Time Data for TQ = 1ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Burst Time')
plt.title('Burst Time Data for TQ = 1ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[39]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P1_RR1.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[2])
  
plt.plot(x, y, color = 'r', linestyle = 'dashed',
         marker = 'o',label = "Turnaround Time Data for TQ = 1ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Turnaround Time')
plt.title('Turnaround Time Data for TQ = 1ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[23]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P2_RR1.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[1])
  
plt.plot(x, y, color = 'g', linestyle = 'dashed',
         marker = 'o',label = "Wait Time Data for TQ = 1ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Wait Time')
plt.title('Wait Time Data for TQ = 1ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[24]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P2_RR1.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[2])
  
plt.plot(x, y, color = 'g', linestyle = 'dashed',
         marker = 'o',label = "Burst Time Data for TQ = 1ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Burst Time')
plt.title('Burst Time Data for TQ = 1ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[25]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P2_RR1.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[2])
  
plt.plot(x, y, color = 'g', linestyle = 'dashed',
         marker = 'o',label = "Turnaround Time Data for TQ = 1ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Turnaround Time')
plt.title('Turnaround Time Data for TQ = 1ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[38]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P1_RR2.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[1])
  
plt.plot(x, y, color = 'r', linestyle = 'dashed',
         marker = 'o',label = "Wait Time Data for TQ = 2ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Wait Time')
plt.title('Wait Time Data for TQ = 2ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[37]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P1_RR2.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[2])
  
plt.plot(x, y, color = 'r', linestyle = 'dashed',
         marker = 'o',label = "Burst Time Data for TQ = 2ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Burst Time')
plt.title('Burst Time Data for TQ = 2ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[36]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P1_RR2.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[2])
  
plt.plot(x, y, color = 'r', linestyle = 'dashed',
         marker = 'o',label = "Turnaround Time Data for TQ = 1ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Turnaround Time')
plt.title('Turnaround Time Data for TQ = 1ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[33]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P2_RR2.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[1])
  
plt.plot(x, y, color = 'g', linestyle = 'dashed',
         marker = 'o',label = "Wait Time Data for TQ = 2ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Wait Time')
plt.title('Wait Time Data for TQ = 2ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[34]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P2_RR2.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[2])
  
plt.plot(x, y, color = 'g', linestyle = 'dashed',
         marker = 'o',label = "Burst Time Data for TQ = 2ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Burst Time')
plt.title('Burst Time Data for TQ = 2ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[35]:


import matplotlib.pyplot as plt
import csv
  
x = []
y = []
  
with open('C:/Users/DHARAM/Downloads/P2_RR2.csv','r') as csvfile:
    lines = csv.reader(csvfile, delimiter=',')
    for row in lines:
        x.append(row[0])
        y.append(row[2])
  
plt.plot(x, y, color = 'g', linestyle = 'dashed',
         marker = 'o',label = "Turnaround Time Data for TQ = 2ms")
  
plt.xticks(rotation = 25)
plt.xlabel('Processes')
plt.ylabel('Turnaround Time')
plt.title('Turnaround Time Data for TQ = 2ms', fontsize = 20)
plt.grid()
plt.legend()
plt.show()


# In[ ]:




