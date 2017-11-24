# learngit


ADXL345加速度角度补偿原理： 
	
ADXL345芯片旋转一个角度时：
设以下变量 ：
X轴方向的加速度大小为Ax，其与水平线的夹角为a1，与重力加速度g的夹角a
Y轴方向的加速度为Ay，与水平线的加速度为 b1，与重力加速度g的夹角为b
Z轴方向的加速度为Az，与水平线的加速度为 y1，与重力加速度g的夹角为y。
a = 90-a1;
b =90-b1;
y=90-y1;
g在各轴方向上的分量为：Ax = gcosα， Ay = gcosβ ， Az = gcosγ；
故可以推得：
Ax = gcosα = gcos(90- α1) =gsinα1 
Ay = gsinβ1 ， Az = gsin γ1.

继续往下计算得到
gcosα1 = squr(g*g - Ax*Ax);
gcosβ1 =squr (g*g - Ay*Ay);
gcosγ1 =squr(g*g - Az*Az );

根据勾股定理Ax*Ax + Ay*Ay + Az*Az = g*g
 cosα1 = squr(g*g - Ax*Ax) / g
 tanα1 =( Ax/g) / [squr(g*g - Ax*Ax) / g] = Ax / squr(g*g - Ax*Ax) = Ax / squr(Ay*Ay + Az*Az) 
 同理可推:
 tanβ1 =  Ay / squr(Ax*Ax+Az*Az) 
 tanγ1 =  Az / squr(Ax*Ax +Ay*Ay

 于是得到公式: 
θx = α1*180/π = [arctan(Ax / squr(Ay*Ay + Az*Az))] *180/π
θy =β1*180/π = [arctan(Ay / squr(Ax*Ax+Az*Az))]*180/π
θz =γ1*180/π = [arctan( Az / squr(Ax*Ax +Ay*Ay))]*180/π)
