import json
import time

from stomp_ws.client import Client
import logging


def print_frame(frame):
    print(json.loads(frame.body))


if __name__ == '__main__':
    LOG_FORMAT = "%(asctime)s - %(levelname)s - %(message)s"
    logging.basicConfig(level=logging.DEBUG, format=LOG_FORMAT)

    # open transport
    client = Client("ws://127.0.0.1:8080/ws")

    # connect to the endpoint
    client.connect(timeout=0)

    # subscribe channel
    client.subscribe("/queue/messages", callback=print_frame)

    time.sleep(100)

    client.disconnect()
