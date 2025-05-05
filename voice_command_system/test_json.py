import json

result = {"action": "search", "name": "Ali"}
print(json.dumps(result, ensure_ascii=False))
