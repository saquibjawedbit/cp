import paho.mqtt.client as mqtt

# Callback when connected to the broker
def on_connect(client, userdata, flags, reason_code, properties):
    print(f"Connected with result code {reason_code}")
    client.subscribe("KEPSeverEX-IOT-Gateway")  # Change to your actual topic

# Callback when a message is received
def on_message(client, userdata, msg):
    print(f"Topic: {msg.topic}, Message: {msg.payload.decode()}")

# Create MQTT client
mqttc = mqtt.Client(mqtt.CallbackAPIVersion.VERSION2)
mqttc.on_connect = on_connect
mqttc.on_message = on_message

# Connect to KEPServerEX MQTT broker
mqttc.connect("localhost", 1883, 60)  # Ensure the broker is running

# Start MQTT loop
mqttc.loop_forever()
