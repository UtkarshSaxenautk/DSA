import fetch from 'node-fetch'

import Client from 'shopify-buy'


const client = Client.buildClient({
    domain:'https://messoldtech-test.myshopify.com',
    storefrontAccessToken: 'c1ead05360c18ca6c3a1b1ea32c5ab48'
});

const clientWithTranslatedContent = Client.buildClient({
    domain: 'https://messoldtech-test.myshopify.com',
    storefrontAccessToken: 'c1ead05360c18ca6c3a1b1ea32c5ab48',
    language: 'ja-JP'
  } , fetch);


client.product.fetchAll().then((res)=> {
    console.log(res);
    
})