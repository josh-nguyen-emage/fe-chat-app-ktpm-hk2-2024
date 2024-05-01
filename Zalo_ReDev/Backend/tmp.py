import json
import stomp

# Define a class to handle message reception
class MyListener(stomp.ConnectionListener):
    def on_error(self, headers, message):
        print('Received an error "%s"' % message)

    def on_message(self, headers, message):
        print('Received a message "%s"' % message)

try:
    # Create a connection to the STOMP server
    conn = stomp.Connection([('localhost:8080/conversation')])  # Connecting to localhost on port 8080 using WebSocket

    # Set up the listener
    conn.set_listener('', MyListener())

    # Connect to the server
    conn.connect(wait=True)

    # Subscribe to the /queue/messages destination
    conn.subscribe(destination='/queue/messages', id=1, ack='auto')

    # Create a JSON message
    json_message = {
        "textBody": "hello there"
    }

    # Convert the JSON message to a string
    message_str = json.dumps(json_message)

    # Send the JSON message to /app/conversations
    conn.send(body=message_str, destination='/app/conversations', headers={'content-type': 'application/json'})

    # Wait for messages
    while True:
        pass  # In a real-world application, you might perform other tasks here

    # Disconnect from the server
    conn.disconnect()

except stomp.exception.ConnectFailedException as e:
    print("Connection to STOMP server failed:", e)
    # Handle the exception, such as retrying the connection or exiting the program gracefully
