import requests

url = 'http://localhost:8080/chatapp/api/media/upload'
files = {'media_file': open("C:/Users/Admin/Desktop/image/output_image.png", 'rb')}

response = requests.post(url, files=files)

print(response.text)