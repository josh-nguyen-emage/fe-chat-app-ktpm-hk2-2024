import json
import time
from stomp_ws.client import Client
import sys


def print_frame(frame):
    print(json.loads(frame.body), flush=True)


if __name__ == "__main__":
    # LOG_FORMAT = "%(asctime)s - %(levelname)s - %(message)s"
    # logging.basicConfig(level=logging.DEBUG, format=LOG_FORMAT)

    # open transport
    client = Client("ws://127.0.0.1:8080/chatapp/ws")

    # connect to the endpoint
    client.connect(timeout=0)

    # subscribe channel
    # client.subscribe("/topic/conversations/3", callback=print_frame)
    client.subscribe(sys.argv[1], callback=print_frame)
    
    while True:
        time.sleep(2)
        print("ping, fuck")

    client.disconnect()
