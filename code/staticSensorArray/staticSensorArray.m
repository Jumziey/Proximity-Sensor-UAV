clear all
robj = linspace(0.01,1,20);
nrSens = linspace(1,20,20);
#Least distance we'll find an object with, worst case scenario
#Assuming a 20cm cone radius on the sonar. 
oDist = @(r,n) (r-0.2)./tan(pi./n);

[rr ss] = meshgrid(robj,nrSens);
d = oDist(rr,ss);
mesh(rr,ss,d)
axis([0 1 1 20 0 10])
xlabel("Radius of object [m]")
ylabel("Number of sensors")
zlabel("Shortest Distance to Object recognition")
title("Ideal Line Width Sonar Recognition")

#Find all static configurations that find objects on a 2 meter distance.
k = 0;
opt = [];
for i=robj;
	for j=nrSens;
		dist = oDist(i,j);
		if abs(dist-2) <0.2;
			opt = [opt [i-0.30;j]];
			k = k+1;
		end
	end
end

