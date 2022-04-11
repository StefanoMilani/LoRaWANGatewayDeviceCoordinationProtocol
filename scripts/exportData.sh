#!/bin/bash

printf "###########################################\n########## OMNeT++ data exporter ##########\n###########################################\n"

if [ $# -lt 1 ]
then
    printf "No file to open!\nUsage: ${0} <filename.vec>\n"
    exit 1
fi

# Exit on error
set -e

# Get current datetime as yyyy mm dd HH MM SS
strtime=$(date "+%Y%m%d_%H%M%S")

# Create directory that will contain exported data
out_directory="exported_data_${strtime}/"
mkdir $out_directory

# Export data into a single CSV file in the new directory
out_export_file="${out_directory}export.csv"
printf "\nExporting data into $out_export_file\n"
opp_scavetool x $1 -o $out_export_file

# Export data from the new CSV file to obtain a CSV file for each stats vector 
printf "\nSplitting exported data in many CSV files\n"
python3 splitExportedData.py $out_export_file -o $out_directory

# Get nested directory name where the multiple CSV files are stored
stats_directory=$(find $out_directory -mindepth 1 -maxdepth 1 -type d)
echo "Data splitted into $stats_directory"

printf "\nTrying to merge some CSV files to obtain explicit files for implicit data\n"

# Append "/" to the directory path if not already present
if [ ! ${stats_directory: -1} = "/" ]
then
    stats_directory+="/"
fi

# Create csv file merging received and lost messages to obtain IN messages ignoring missing files (here lost messages)
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[0]_messageInCount.csv -i ${stats_directory}gateways[0]_messageReceivedCount.csv ${stats_directory}gateways[0]_messageLostCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[0]_messageInLoRaCount.csv -i ${stats_directory}gateways[0]_messageReceivedLoRaCount.csv ${stats_directory}gateways[0]_messageLostLoRaCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[0]_messageInIpCount.csv -i ${stats_directory}gateways[0]_messageReceivedIpCount.csv ${stats_directory}gateways[0]_messageLostIpCount.csv &

# Create csv file merging received and lost messages to obtain IN messages ignoring missing files (here lost messages)
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[1]_messageInCount.csv -i ${stats_directory}gateways[1]_messageReceivedCount.csv ${stats_directory}gateways[1]_messageLostCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[1]_messageInLoRaCount.csv -i ${stats_directory}gateways[1]_messageReceivedLoRaCount.csv ${stats_directory}gateways[1]_messageLostLoRaCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[1]_messageInIpCount.csv -i ${stats_directory}gateways[1]_messageReceivedIpCount.csv ${stats_directory}gateways[1]_messageLostIpCount.csv &

# Create csv file merging received and lost messages to obtain IN messages ignoring missing files (here lost messages)
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[2]_messageInCount.csv -i ${stats_directory}gateways[2]_messageReceivedCount.csv ${stats_directory}gateways[2]_messageLostCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[2]_messageInLoRaCount.csv -i ${stats_directory}gateways[2]_messageReceivedLoRaCount.csv ${stats_directory}gateways[2]_messageLostLoRaCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}gateways[2]_messageInIpCount.csv -i ${stats_directory}gateways[2]_messageReceivedIpCount.csv ${stats_directory}gateways[2]_messageLostIpCount.csv &

# Create csv file merging received and lost messages to obtain IN messages ignoring missing files (here lost messages)
python3 mergeCSV.py -r -I -o ${stats_directory}endDevices[0]_messageInCount.csv -i ${stats_directory}endDevices[0]_messageReceivedCount.csv ${stats_directory}endDevices[0]_messageLostCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}endDevices[1]_messageInCount.csv -i ${stats_directory}endDevices[1]_messageReceivedCount.csv ${stats_directory}endDevices[1]_messageLostCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}endDevices[2]_messageInCount.csv -i ${stats_directory}endDevices[2]_messageReceivedCount.csv ${stats_directory}endDevices[2]_messageLostCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}endDevices[3]_messageInCount.csv -i ${stats_directory}endDevices[3]_messageReceivedCount.csv ${stats_directory}endDevices[3]_messageLostCount.csv &
python3 mergeCSV.py -r -I -o ${stats_directory}endDevices[4]_messageInCount.csv -i ${stats_directory}endDevices[4]_messageReceivedCount.csv ${stats_directory}endDevices[4]_messageLostCount.csv &

# Wait parallel executions end
wait

printf "\n"

# Plot data
./plotData.sh $stats_directory