import requests
import sys

def upload_image(image_path):
    url = 'http://localhost:8080/chatapp/api/media/upload'
    files = {'media_file': open(image_path, 'rb')}
    response = requests.post(url, files=files)
    
    print(response.text)

def main():
    image_path = sys.argv[1]
    upload_image(image_path)

if __name__ == "__main__":
    main()
