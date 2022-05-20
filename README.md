# gas-leakage-detection-step-programming
Step-by-step programming for gas leakage detection

# Hardware required

# IoT platform setup
We are using the Thingsboard demo IoT platform.

****Step 1:Provision Device****

Login to demo.thingsboard.io and click on "Devices" on the side menu
In the devices page, click on the "+" icon to create a new device
Input the name of your choice for the device, then click "add"

****Step 2: Connect Device****

Get the device credentials. Click on the new device you created, on the resulting window, click on "copy access token" and paste
To connect, we will send telemetry. Which means, send data to the platform. There are different protocols for sending data.
You can send data via HTTP, MQTT, MODBUS, LORAWAN etc. We will be using HTTP.

On command prompt, write this command:
curl -v -X POST -d "{\"Gas level\": 25}" $THINGSBOARD_HOST_NAME/api/v1/$ACCESS_TOKEN/telemetry --header "Content-Type:application/json"

$THINGSBOARD_HOST_NAME = demo.thingsboard.io
$ACCESS_TOKEN = the token you copied from step 2

Press enter.

On the devices window, click on your device, in the resulting window, click on "latest telemetry", you will see the information that you just sent.

****Step 3: Create Dashboard:****

****3.1: Create empty dashboard:****
Open the dashboard page, click the "+" icon in the top right corner. Select "Create New Dashboard"
Input dashboard name as the one you wish, then click "Add" to add the dashboard
Click on the new dashboard you created. On the resulting page, click on the "Open Dashboard" button

****3.2: Add entity alias:****
1. _On the bottom right corner of the page resulting from the click of the "Open Dashboard" button, you will see a pencil icon. Click on it to enter edit mode_
2. _Click on entity aliases. It is the next icon after the gear icon on the top of this window_
3. _Click "Add alias"_
4. _Input alias name, for example, "MyDevice". Select the "Single entity" Filter type. Select "Device" as Type and type "My New" to enable autocomplete. Choose your device from the auto-complete and click on it._
