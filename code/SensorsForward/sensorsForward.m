function distance = sensorsForward(DFromHex,RadOfHex,RadOfObj)
    %DFromHex = distance in front of hexacopter you want to look
    %RadOfHex = radius of hexacopter
    %RadOfObj = radius if the object you are looking at.
    angle = 2*atan(RadOfHex/DFromHex);
    %used to find worst case scenario
distance=zeros(20,2);
    
    for nrSensors=1:20
        distance(nrSensors,1)=nrSensors;
        theta = angle/(nrSensors - 1);
        b=sin(theta/2);
        k=0;
        for r=0.1:0.01:3
            c=2*r*b;
            if abs(RadOfObj-(c/2-0.2)) < 0.1 && k==0 
                distance(nrSensors,2) = r;
                k=1;
                else if distance(nrSensors,2)==0 && nrSensors ~= 1
                    distance(nrSensors,2) = 3;
             
                    end
            end
        end
    end
    plot(nrSensors,distance(:,2));
        
    end
