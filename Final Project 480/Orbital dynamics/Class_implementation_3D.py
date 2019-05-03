#Importing the Packages needed

from mpl_toolkits import mplot3d
import matplotlib.pyplot as plt
from IPython.display import display, clear_output
import numpy as np
import time

class planet():
    def __init__ (self,x0,y0,z0,v0x,v0y,v0z,m,n_iter,tstep):
        self.x=x0
        self.y=y0
        self.z=z0
        self.v_x=v0x
        self.v_y=v0y
        self.v_z=v0z
        self.mass=m
        self.n_iter=n_iter
        self.tstep=tstep
    
    def velocities(self,x0,y0,z0,m,tstep,vx,vy,vz):
        r=np.sqrt(x0**2+y0**2)
        a=-m/r**2
        theta=np.arctan2(y0,x0)
        vy=np.sin(theta)*a*tstep+vy
        vx=np.cos(theta)*a*tstep+vx
        vz=np.cos(theta)*a*tstep+vz
        
        return vx,vy,vz, theta
    
    def orbit (self):
        x0=self.x
        y0=self.y
        z0=self.z
        v0x=self.v_x
        v0y=self.v_y
        v0z=self.v_z
        m=self.mass
        n_iter=self.n_iter
        tstep=self.tstep
        
        xs=[x0]
        ys=[y0]
        zs=[z0]
        thetas=[]
        for i in range (0,n_iter):
            v0x,v0y,v0z,theta = self.velocities(x0,y0,z0,m,tstep,v0x,v0y,v0z)
            x0+=v0x*tstep
            y0+= v0y*tstep
            z0+= v0z*tstep
            xs.append(x0)
            ys.append(y0)
            zs.append(z0)
            thetas.append(theta)

            #creating a tail for the planet trajectory
            if len(xs) > 10:
                xs1 = xs[-10:-1]
                ys1 = ys[-10:-1]
                zs1 = zs[-10:-1]
                c1 = np.array([i for i in range(len(xs1))])
            else:
                xs1 = xs
                ys1 = ys
                zs1 = zs
                c1 = np.array([i for i in range(len(xs1))])


            fig = plt.figure(figsize = (15,8))
            ax = fig.add_subplot(111, projection='3d')
            fig.patch.set_facecolor('cyan')
            #plt.rcParams['axes.facecolor'] = 'grey'
            plt.scatter(xs1,ys1, zs1, c = c1, cmap = 'Reds')
            plt.scatter(0,0,c="blue", s=100)
            plt.title('Planet orbiting')
            ax.axes.set_xlim3d(left=-800, right=800) 
            ax.axes.set_ylim3d(bottom=-800, top=800) 
            ax.axes.set_zlim3d(bottom=-800, top=800)

            time.sleep(0.2)
            clear_output(wait=True) # Clear output for dynamic display
            display()            # Reset display
            plt.show()
            fig.clear()             # Prevent overlapping and layered plots
            plt.close();
        return xs, ys, zs, thetas