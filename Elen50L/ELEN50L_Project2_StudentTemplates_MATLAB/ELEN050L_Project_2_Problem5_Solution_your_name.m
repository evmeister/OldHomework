%% ELEN 050L (Electric Circuits I): Project 2, Problem 5, Evan Eberhardt, Ryan Meyer
%
% <<ELEN050L_Project_2_figure_02.png>>
%
% <<ELEN050L_Project_2_Problem_05.png>>
%
% *Hard Copy Deliverables:*
%
% # A MATLAB script and publish the solution using MATLAB's *publish*
% feature.
% # Turn in MATLAB scripts and a document of the run-time results.
% # Turn in the Excel file with the measured results.
%
%% Initialize MATLAB Environment
%

clear; clc; clf; cla; close all;
format short; format compact;


% These values are used for plotting purposes.
fignum = 0;

%% Problem 7
%
% <<ELEN050L_Project_2_Problem_07.png>>
%

% Define the standard component values 
R1 = 1000;             % Ohms
R2 = 10000;            % Ohms
C1 = 0.000001;         % Farads
C2 = 0.0000001;        % Farads

% Target design criteria
A_0_target = 10;     w_0 = 0;        % Amplitude (unitless) at rad/sec
A_1_target = 10;      w_1 = 10000;    % Amplitude (unitless) at rad/sec

% Specify the w variable for characterzation purposes
w = [1:1:10^3,10^3+1:10:2.5e5];

% Shortened version of Apendix 3 function F = freqresp2(Rl,R2,C,w)
den = R1*(sqrt(1+(w.*R2.*C2).^2));
num = R2*(sqrt(1+(w.*R1.*C1).^2));
% In this case, the numerator is a function of the frequency.
A = num./den;
% The command ./ divides each element of vector num by the
% corresponding element of vector den. As a result, the elements
% of A represent the amplitude at different frequencies.

F = 20*log10(A);
% This is necessary in order to represent the amplitude in decibels.

% Generate the plot for the actual design.
fignum = fignum+1; figObj = figure(fignum);   % Establish a figure number
set(fignum, 'Name', ['Problem 5 A(w)']);      % Name the figure
semilogx(w, F); grid on;
ylabel('Amplitude (dB)');
xlabel('Frequency (rad/s)');
axis([min(w), max(w), 0, 25]);
title ('Problem 5 Solution');

%% Problem 7 actual design verification point 1
%

% Calculate the first target design point A(w).
den = R1*(sqrt(1+(w_0*R2.*C2).^2));
num = R2*(sqrt(1+(w_0*R1.*C1).^2));
% In this case, the numerator is a function of the frequency.
A_0_design = num./den;

% Calculate the percent difference for the first target design point A(w).
diff_0 = (A_0_design - A_0_target)/(A_0_target)*100;
fprintf('\nTarget A(%-6.1f) = %-6.4f .\n', w_0, A_0_target);
fprintf('\nDesign A(%-6.1f) = %-6.4f .\n', w_0, A_0_design);
fprintf('\n%%diff = %-6.4f .\n', diff_0);

%% Problem 7 actual design verification point 2
%

% Calculate the second target design point A(w).
den = R1*(sqrt(1+(w_1*R2.*C2).^2));
num = R2*(sqrt(1+(w_1*R1.*C1).^2));
% In this case, the numerator is a function of the frequency.
A_1_design = num./den;

% Calculate the percent difference for the second target design point A(w).
diff_1 = (A_1_design - A_1_target)/(A_1_target)*100;
fprintf('\nTarget A(%-6.1f) = %-6.4f .\n', w_1, A_1_target);
fprintf('\nDesign A(%-6.1f) = %-6.4f .\n', w_1, A_1_design);
fprintf('\n%%diff = %-6.4f .\n', diff_1);

%% Problem 8
%
% <<ELEN050L_Project_2_Problem_08.png>>
%

% Import Excel measurements for Problem 5
[freq_meas,Vg_meas_5,Vo_meas_5] = importfile_problem5...
    ('ELEN050L_Project_2_Problem_5_Measured_Results.xlsx','Sheet1',2,80);

% Define measured values for the circuit elements.
R1_meas = 1000;               % Ohms
R2_meas = 10000;              % Ohms
C1_meas = .000001;            % Farads
C2_meas = .0000001;           % Farads
Vcc_p_meas = 15;              % Volts
Vcc_n_meas = -15;             % Volts

% Calculate A_meas(w) using the measured data.
A_meas = Vo_meas_5./Vg_meas_5;
% Convert A_meas(w) to decibels.
F_meas = 20*log10(A_meas);
% Convert frequency in Hertz to radians/second.
w_meas = 2*pi*freq_meas;

% Generate the plot for the measured actual design.
fignum = fignum+1; figObj = figure(fignum);   % Establish a figure number
set(fignum, 'Name', ['Problem 5 A_meas(w)']); % Name the figure
semilogx(w_meas, F_meas); grid on;
ylabel('Amplitude (dB)');
xlabel('Frequency (rad/s)');
axis([min(w_meas), max(w_meas), 0, 25]);
title ('Problem 5 Solution (Measured)');

%% Problem 8 measured design verification point 1
%

% Extract the first target design point A_meas(w).
A_0_measured = A_meas(1);

% Calculate the percent difference for the first measured design point
% A_meas(w).
diff_0_meas = (A_0_measured - A_0_design)/(A_0_design)*100;
fprintf('\nMeasured A(%-6.1f) = %-6.4f .\n', w_meas(1), A_0_measured);
fprintf('\nDesign A(%-6.1f) = %-6.4f .\n', w_0, A_0_design);
fprintf('\n%%diff_meas = %-6.4f .\n', diff_0_meas);

%% Problem 8 measured design verification point 2
%

% Extract the second target design point A_meas(w).
A_1_measured = A_meas(37);

% Calculate the percent difference for the second measured design point
% A_meas(w).
diff_1_meas = (A_1_measured - A_1_design)/(A_1_design)*100;
fprintf('\nMeasured A(%-6.1f) = %-6.4f .\n', w_meas(1), A_1_measured);
fprintf('\nDesign A(%-6.1f) = %-6.4f .\n', w_0, A_1_design);
fprintf('\n%%diff_meas = %-6.4f .\n', diff_1_meas);

%% Program execution complete
%

display(' ');
disp('Program execution complete....');

%% MATLAB code listing
%