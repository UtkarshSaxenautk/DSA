


let gold_pricelist = [
    {
        "carrat":24,
        "value":200

    },
    {
        "carrat":23,
        "value":180

    },
    {
        "carrat":22,
        "value":160

    },
    {
        "carrat":21,
        "value":140

    },
    {
        "carrat":20,
        "value":120

    },
    {
        "carrat":19,
        "value":100

    },
    {
        "carrat":18,
        "value":80

    },
    {
        "carrat":17,
        "value":60

    },
   
    
    {
        "carrat":16,
        "value":40

    },
    {
        "carrat":15,
        "value":20

    },
    {
        "carrat":14,
        "value":10

    },
    

]

let Silver = {
    "value":300
}


// const calculate_for_silver = (quantity) => {
//     const q = parseInt(quantity);
//     console.log(Silver.value * quantity);
// }


const calculate = (metal, quantity , carrat) => {
   if(metal === "Silver"){
      const q = parseInt(quantity);
      console.log(Silver.value * quantity);
   } else if(metal === "Gold"){
     
    gold_pricelist.forEach(element => {
        if(element.carrat === carrat){
            console.log(element.value * quantity);
        }
     });
}
}



calculate("Gold" , 100 , 24)
calculate("Silver" , 120 , null);