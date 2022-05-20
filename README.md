# gas-leakage-detection-step-programming
Step-by-step programming for gas leakage detection

# Hardware required

# IoT platform setup
We are using the Thingsboard demo IoT platform.

Step 1:Provision Device
Login to demo.thingsboard.io and click on "Devices" on the side menu
In the devices page, click on the "+" icon to create a new device
Input the name of your choice for the device, then click "add"

Step 2: Connect Device
Get the device credentials. Click on the new device you created, on the resulting window, click on "copy access token" and paste
To connect, we will send telemetry. Which means, send data to the platform. There are different protocols for sending data.
You can send data via HTTP, MQTT, MODBUS, LORAWAN etc. We will be using HTTP.

On command prompt, write this command:
curl -v -X POST -d "{\"Gas level\": 25}" $THINGSBOARD_HOST_NAME/api/v1/$ACCESS_TOKEN/telemetry --header "Content-Type:application/json"

$THINGSBOARD_HOST_NAME = demo.thingsboard.io
$ACCESS_TOKEN = the token you copied from step 2

Press enter.

