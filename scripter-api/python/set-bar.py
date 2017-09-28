import scripterapi

# print(Sample.margin.top)
# Sample.margin.top = 150
# print(Sample.margin.top)
document = Sample.document
print("python document.a "+str(document.a))
print("python sample.document.a "+str(Sample.document.a))
print("python sample.a "+str(Sample.a))
Sample.document.a = 21
print("python sample.document.a "+str(Sample.document.a))
