class Test {

    val low = 20
    val high = 50

    fun main() {

        var index = low
        var result : bool = true

        while (index < high) {

            result = true
            
            var num = index / 2
            
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

            index = index + 1
        }
    }
}