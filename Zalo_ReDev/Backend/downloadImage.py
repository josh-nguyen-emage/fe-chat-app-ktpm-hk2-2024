import requests

url = 'http://localhost:8080/chatapp/api/media/download/3'

response = requests.get(url)

if response.status_code == 200:
    with open('downloaded_file.png', 'wb') as f:
        f.write(response.content)
    print("File downloaded successfully.")
else:
    print("Failed to download file. Status code:", response.status_code)
