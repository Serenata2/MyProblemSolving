inp=int(input())
fn, fn_1, fn_2=0, 0, 1
if inp>=2:
    for _ in range(inp):
        fn=fn_1+fn_2
        fn_2=fn_1
        fn_1=fn
    print(fn)

else:
    print(inp)