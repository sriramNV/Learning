class ArrayRotation():
    def lRotate(self,arr,rot,size):
        rot = rot % size
        g_c_d = self.gcdFinder(rot, size)
        for i in range(0,g_c_d):
            temp = arr[i]
            j = i
            while True:
                k = j + rot
                if k >= size:
                    k -= size
                if k == i:
                    break
                arr[j] = arr[k]
                j = k
            arr[j] = temp

    def gcdFinder(self,a,b):
        if a > b:
            small = b
        else:
            small = a
        for i in range(1, small+1):
            if((a % i == 0) and (b % i == 0)):
                gcd = i
        return gcd

a = ArrayRotation()

size = int(input("\nEnter size of the array: "))
arr = list(map(int,input().split()))
# arr = list(map(int, input("\nEnter elements in a single line with a space between each element: ").strip().split()))
rot = int(input("\nEnter number of left rotations to be performed: "))
a.lRotate(arr=arr,rot=rot,size=size)
print(arr)

