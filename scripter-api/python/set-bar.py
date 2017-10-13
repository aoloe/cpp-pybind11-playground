import scripterapi

# print(Sample.margin.top)
# Sample.margin.top = 150
# print(Sample.margin.top)
document = Sample.document

print("python document.margin.top "+str(document.margin.top))
Sample.document.margin.top = 21
print("python document.margin.top "+str(document.margin.top))
Sample.document.getPage(1).margin.top = 21
print("python page 1 margin.top "+str(document.getPage(1).margin.top))
Sample.document.getPage(1).margin.top = 42
print("python page 1 margin.top "+str(document.getPage(1).margin.top))
