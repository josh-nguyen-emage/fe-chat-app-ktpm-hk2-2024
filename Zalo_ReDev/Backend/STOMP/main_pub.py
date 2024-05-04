import json
import time
import sys

from stomp_ws.client import Client
import logging


def print_frame(frame):
    print(json.loads(frame.body))


if __name__ == "__main__":
    # LOG_FORMAT = "%(asctime)s - %(levelname)s - %(message)s"
    # logging.basicConfig(level=logging.DEBUG, format=LOG_FORMAT)

    # open transport
    client = Client("ws://127.0.0.1:8080/chatapp/ws")

    # connect to the endpoint
    client.connect(timeout=30000)

    # send msg to channel
    # client.send(
    #     "/app/sendMessage",
    #     body=json.dumps(
    #         {
    #             "textBody": "Ok, this is work",
    #             "senderId": "1",
    #             "conversationId": "3",
    #             "sendTime": "2024-05-01T10:21:45.421953",
    #         }
    #     ),
    # )

    client.send(
        "/app/sendMessage",
        body=sys.argv[1],
    )
    client.disconnect()

    print("done")
