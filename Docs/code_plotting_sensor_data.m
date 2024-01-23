

%% Code for plotting sensors data collecitons
fs = 5; % for data units transfering to time in minute
data_length = 1600; % for filtering data
t = (0:data_length-1)./fs; 

figure; 
IMU_data_x = IMU_data(:,1);
IMU_data_y = IMU_data(:,2);
IMU_data_z = IMU_data(:,3);

subplot(321);  plot(t,IMU_data_x(1:1600)); hold on; 
ylabel('IMU Data Axes 1'); 
title('IMU Data (X, Y, Z Axes)');
xlabel('Time (Minutes)');

subplot(323);  plot(t,IMU_data_y(1:1600)); hold on; 
ylabel('IMU Data Axes 2'); 
xlabel('Time (Minutes)');

subplot(325);  plot(t,IMU_data_z(1:1600)); hold on; 
ylabel('IMU Data Axes 3'); 
xlabel('Time (Minutes)');

% figure; 
subplot(322); 
plot(t,environ_temp(1:1600)); hold on; 
ylim([23,30]); 
xlabel('Time (Minutes)');
title('Temperature (Celcius)');

subplot(324);  
plot(t,environ_humid(1:1600)); hold on; 
ylim([32,35]);
xlabel('Time (Minutes)');
title('Humidity (%)')

subplot(326); 
plot(t,environ_heat_index(1:1600)); hold on; 
xlabel('Time (Minutes)');
title('Heat Index')



%% Code for plotting UWB and BLE data graphs

figure ; 
subplot(711); plot(medfilt1(clean_data_50_250,3),'r'); 
subplot(712); hold on; plot(medfilt1(clean_data_250_450,3),'r');
subplot(713); hold on;  plot(medfilt1(clean_data_450_750,3),'r');
subplot(714); hold on; plot(medfilt1(clean_data_750_1050,3),'r');
subplot(715); hold on; plot(medfilt1(clean_data_1050_1250,3),'r');
subplot(716);hold on;  plot(medfilt1(clean_data_1250_1550,3),'r');
subplot(717); hold on; plot(medfilt1(clean_data_1550_1750,3),'r');

close all; clc; 
errorbar(1,median(clean_data_50_250),iqr(clean_data_50_250),'ko');  hold on; 
errorbar(2,median(clean_data_250_450),iqr(clean_data_250_450),'ok'); 
errorbar(3,median(clean_data_450_750),iqr(clean_data_450_750),'ko'); 
errorbar(4,median(clean_data_750_1050),iqr(clean_data_750_1050),'ok'); 
errorbar(5,median(clean_data_1050_1250),iqr(clean_data_1050_1250),'ok'); 
errorbar(6,median(clean_data_1250_1550),iqr(clean_data_1250_1550),'ko'); 
errorbar(7,median(clean_data_1550_1750),iqr(clean_data_1550_1750),'ko'); 

xlim([0,8]); 
x = 1:7;
y1 = A; 
scatter(x,y1,25,'b','s')
hold on;
lsline;

%
A = [median(clean_data_50_250);...
    median(clean_data_250_450);...
    median(clean_data_450_750);...
    median(clean_data_750_1050);...
    median(clean_data_1050_1250);...
    median(clean_data_1250_1550);...
    median(clean_data_1550_1750)]; 

% plotting fitting / linear regression line 
x = 1:7;
y1 = A; 
scatter(x,y1,25,'b','s')
hold on;
lsline;

subplot(221); 
plot(All_data) ; hold on; 
plot(med_all_data,'r'); 

subplot(222); 
plot(BLE_data) ; hold on;

subplot(223); 
errorbar(1,median(clean_data_50_250),iqr(clean_data_50_250),'ko');  hold on; 
errorbar(2,median(clean_data_250_450),iqr(clean_data_250_450),'ok'); 
errorbar(3,median(clean_data_450_750),iqr(clean_data_450_750),'ko'); 
errorbar(4,median(clean_data_750_1050),iqr(clean_data_750_1050),'ok'); 
errorbar(5,median(clean_data_1050_1250),iqr(clean_data_1050_1250),'ok'); 
errorbar(6,median(clean_data_1250_1550),iqr(clean_data_1250_1550),'ko'); 
errorbar(7,median(clean_data_1550_1750),iqr(clean_data_1550_1750),'ko'); 

xlim([0,8]); 
x = 1:7;
y1 = A; 
scatter(x,y1,25,'b','s')
hold on;
lsline;

subplot(224); 
errorbar(median_BLE_mean,iqr_BLE_mean,'o'); hold on; 
xlim([0,8])
x = 1:7;
B = median_BLE_mean;
scatter(x,B,25,'b','s')
lsline


