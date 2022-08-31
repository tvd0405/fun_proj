clear all;close all;
N=48;
b = fir1(N,[0.35 0.65]);
freqz(b,1,512)
load chirp
%plot(y)
y_fix=fi(y,1,8,7);
b_fix=fi(b,1,8,7);
out=filter(b,1,y);
out_fix=filter(b_fix,1,y_fix);
figure; plot(linspace(-Fs/2,Fs/2,length(y)),fftshift(abs(fft(y))))
figure; plot(linspace(-Fs/2,Fs/2,length(out)),fftshift(abs(fft(out))))
figure; plot(linspace(-Fs/2,Fs/2,length(out_fix.double())),fftshift(abs(fft(out_fix.double))))
%% 
dlmwrite("input.dat",y);
dlmwrite("coef.dat",b);
%% 
load("output.dat");
%figure;plot(output);
figure; plot(linspace(-Fs/2,Fs/2,length(output)),fftshift(abs(fft(output))))