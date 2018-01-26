function [freqmeas,Vgmeas6,Vomeas6] = importfile_problem6(workbookFile,sheetName,startRow,endRow)
%IMPORTFILE Import data from a spreadsheet
%   [freqmeas,Vgmeas6,Vomeas6] = IMPORTFILE(FILE) reads data from the first
%   worksheet in the Microsoft Excel spreadsheet file named FILE and
%   returns the data as column vectors.
%
%   [freqmeas,Vgmeas6,Vomeas6] = IMPORTFILE(FILE,SHEET) reads from the
%   specified worksheet.
%
%   [freqmeas,Vgmeas6,Vomeas6] = IMPORTFILE(FILE,SHEET,STARTROW,ENDROW)
%   reads from the specified worksheet for the specified row interval(s).
%   Specify STARTROW and ENDROW as a pair of scalars or vectors of matching
%   size for dis-contiguous row intervals. To read to the end of the file
%   specify an ENDROW of inf.
%
%	Non-numeric cells are replaced with: NaN
%
% Example:
%   [freqmeas,Vgmeas6,Vomeas6] =
%   importfile_problem6('ELEN050L_Project_2_Problem_6_Measured_Results.xlsx','Sheet1',2,80);
%
%   See also XLSREAD.

% Auto-generated by MATLAB on 2014/11/25 16:25:18

%% Input handling

% If no sheet is specified, read first sheet
if nargin == 1 || isempty(sheetName)
    sheetName = 1;
end

% If row start and end points are not specified, define defaults
if nargin <= 3
    startRow = 2;
    endRow = 80;
end

%% Import the data
[~, ~, raw] = xlsread(workbookFile, sheetName, sprintf('A%d:C%d',startRow(1),endRow(1)));
for block=2:length(startRow)
    [~, ~, tmpRawBlock] = xlsread(workbookFile, sheetName, sprintf('A%d:C%d',startRow(block),endRow(block)));
    raw = [raw;tmpRawBlock]; %#ok<AGROW>
end
raw(cellfun(@(x) ~isempty(x) && isnumeric(x) && isnan(x),raw)) = {''};

%% Replace non-numeric cells with NaN
R = cellfun(@(x) ~isnumeric(x) && ~islogical(x),raw); % Find non-numeric cells
raw(R) = {NaN}; % Replace non-numeric cells

%% Create output variable
data = reshape([raw{:}],size(raw));

%% Allocate imported array to column variable names
freqmeas = data(:,1);
Vgmeas6 = data(:,2);
Vomeas6 = data(:,3);

