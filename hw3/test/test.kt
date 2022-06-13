class Test {

    fun checkPrimeNumber(num: int): int {


        return 1
    }

    fun main() {
        var low = 20
        val high = 50
        var result:int

        while (low < high) {
            result = checkPrimeNumber(low) 
            if (result == 1){
                print(result)
                print(" ")
                println(low)
            }

            low = low + 1
        }
    }


}