function nrReq = spintime

beamwidth=0.25; % [m] at 2.8m from the sensor
time=zeros(30,8);
nrReq=zeros(8,1);

%angle between the sensors
for nrmeasurements=1:8
    counter = 0;
    for nrsensors=1:30
        angle = 2*pi/nrsensors;

        %circle sector or the edge of what we want to scan
        totaldistance=angle*2.8;

        %how many steps it will require before we scanned the entire intermediate
        %angle
        nrsteps = totaldistance/beamwidth;

        % nrmeasurements is how many measurements you do per second
        % ergo time required to sweep entire distance between sensors is equal to
        % how many steps you have divided by how many steps you do per second
        % resulting in only time as a unit left.
        time(nrsensors,nrmeasurements) = nrsteps/nrmeasurements;
        if time(nrsensors,nrmeasurements)<=1 && counter ==0
            nrReq(nrmeasurements)=nrsensors;
            counter=1;
        end
    end
end
hold on;
mesh(time);
title('A plot of how time changes with respect to the number of sensors and #measurments per second')
ylabel('# Sensors')
xlabel('# Measurements per second')
zlabel(' Sweep time per measurement frequency')

end