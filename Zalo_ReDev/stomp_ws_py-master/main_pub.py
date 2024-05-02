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

    # send msg to channel
    client.send("/app/conversations", body=json.dumps({
        'id' : '0',
        'textBody': 'Ok, this is work',
        'senderId': '1',
        'recipientId' : '2',
        'conversationId' : 'id3',
        'edited' : 'false',
        # 'MessageStatus' : 'MessageStatus.RECEIVED',
        'sendTime': '2024-05-01T10:21:45.421953'}))

    time.sleep(100)

    client.disconnect()
