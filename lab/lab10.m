
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
%
%  Programmers and Purdue Email Addresses:
%  1. Atif Niyaz aniyaz@purdue.edu
%  2. Canyu Yang yang1083@purdue.edu
%  3. Ittichot Suwanmungkool isuwanmu@purdue.edu 
%
%  Lab #: 10
%
%  Academic Integrity Statement:
%
%       We have not used source code obtained from
%       any other unauthorized source, either modified
%       or unmodified.  Neither have we provided access 
%       to our code to another. The project we are submitting
%       is our own original work.
%
%  Lab Division and Section: Wednesday, 11:30 - 1:20 PM, SC 198
%
%  Program Description: This program generates a key and a encrypted number from a dataset using a special algorithim
%
%  Listing and Commenting of All Variables Used:
%     dataSet;     // The dataset file
%     i;           // Loop incrementor
%     number;      // A single number from the dataset file
%     key;         // The key that is generated
%     tempEncrypt; // Temporary storage of non-encrypt number
%     encrypted;   // The encrypted number generated
%     temp;        // Temporary storage of key for analyze
%     k;           // Loop incrementor     
%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

dataSet = fopen('labData');

fprintf('\n  #   Number  Key  Encrypted\n');
fprintf('----------------------------\n');

i = 1;
while ~feof(dataSet)
  number = fscanf(dataSet, '%d', 1);
  
  if number ~= 0
    key = number;
    tempEncrypt = number;
    encrypted = 0;

    if key < 10
      key = 0;
    end

    while key >= 10
      temp = key;
      key = 0;

      k = 0;
      
      while temp >= 10
        key = key + abs(mod(floor(temp / 10), 10) - mod(temp, 10)) * power(10, k);
        temp = floor(temp / 10);
        k++;
      end
    end

    k = 0;
  
    while tempEncrypt ~= 0
      encrypted = encrypted + mod(mod(tempEncrypt, 10) + key, 10) * power(10, k);
      tempEncrypt = floor(tempEncrypt / 10);
      k++;
    end
 
    fprintf('%3d%9d%5d%10d\n', i, number, key, encrypted);
    i++;
  end
end

fprintf('\n');
fclose(dataSet);
