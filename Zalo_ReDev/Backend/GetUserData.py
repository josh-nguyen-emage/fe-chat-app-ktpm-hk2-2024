import sys
import requests

def main():
    if len(sys.argv) != 3:
        print("Usage: python script.py <phone_number> <token>")
        return

    token = sys.argv[1]
    phone_number = sys.argv[2]

    url = f'http://localhost:8099/users/{phone_number}'

    headers = {
        'Authorization': f'Bearer {token}'
    }

    response = requests.get(url, headers=headers)

    if response.status_code == 200:
        print(response.text)
    else:
        print("Error:", response.status_code, response.reason)

if __name__ == "__main__":
    main()
