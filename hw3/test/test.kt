class Test {

    var low = 20
    val high = 50

    fun main() {

        var result : bool = true

        while (low < high) {

            result = true
            
            var num = low

            num = num / 2
            
            for (i 2..num) {
                var temp = num % i
                if(result){
                    if(temp != 0)
                        result = false
                }
            }
            
            if (result){
                println(low)
            }

            low = low + 1
        }
    }
}