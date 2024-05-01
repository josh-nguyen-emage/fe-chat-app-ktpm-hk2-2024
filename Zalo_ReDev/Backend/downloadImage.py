import requests
from datetime import datetime
import sys
import imghdr

def download_file(id):
    url = f'http://localhost:8080/chatapp/api/media/download/{id}'

    response = requests.get(url)
    # print(response.headers)

    if response.status_code == 200:
        current_time = datetime.now().strftime("%Y-%m-%d-%H-%M-%S-%f")
        filename = f"{current_time}.{imghdr.what(None, response.content)}"
        
        with open(filename, 'wb') as f:
            f.write(response.content)
        return filename
    else:
        print(f"Failed to download file with ID '{id}'. Status code:", response.status_code)
        return None

def main():
    if len(sys.argv) != 2:
        sys.exit(1)

    id = sys.argv[1]
    filename = download_file(id)
    print(filename)

if __name__ == "__main__":
    main()
