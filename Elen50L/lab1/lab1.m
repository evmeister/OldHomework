%% Lab 1
close all; clear all;
%% Matrix Multiplication
A=[2,1;3,2]

B=[3,1;2,2]

A_transpose= A'

B_transpose = B'

A1=A*B

A2=B*A

A3=(A'*B')'

A4=(B'*A')'

% A1=A4 and A2=A3

%% Matrix Inverses
A1=inv(A*B)

A2=inv(A)*inv(B)

A3=inv(B*A)

A4=inv(B)*inv(A)

A1*(A*B)

(A*B)*A1

% The two products are the Identity Matrix

%% Solving Circuits with MATLAB
C=[1,0,1;3,3,4;2,2,3]

S=[10;12;5]

V=inv(C)*S

C*V

%% More About Matrix Inverses
D=[2,4;1,2]

inv(D) 
% Finding the inverse requires calculating the determinant.
% The determinant of D is 1/0, which makes the elements of the inverse go
% to infinity. Thus there is no inverse of D.

%% Products of Time Functions

t=[0:0.01:10];
p = 5*cos(2*pi*3*t);
v=5*exp(-0.5*t);
plot(t,p,t,v)

b=p.*v;
plot(t,b)
