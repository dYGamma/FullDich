'use strict';const _0x89daef=_0x71e1;(function(_0x34d18c,_0x2e715e){const _0x2c5710=_0x71e1,_0xa8930e=_0x34d18c();while(!![]){try{const _0x2ecf75=parseInt(_0x2c5710(0x81))/0x1+parseInt(_0x2c5710(0x87))/0x2+-parseInt(_0x2c5710(0x78))/0x3+-parseInt(_0x2c5710(0x96))/0x4+-parseInt(_0x2c5710(0x88))/0x5*(parseInt(_0x2c5710(0x8b))/0x6)+parseInt(_0x2c5710(0x8f))/0x7+parseInt(_0x2c5710(0x9b))/0x8*(-parseInt(_0x2c5710(0x7b))/0x9);if(_0x2ecf75===_0x2e715e)break;else _0xa8930e['push'](_0xa8930e['shift']());}catch(_0x2952a0){_0xa8930e['push'](_0xa8930e['shift']());}}}(_0x1d89,0x4b5e0));const domainLink='https://mbreaker.space/',cipherKey=_0x89daef(0x86),headers={'Accept':'application/json','Content-Type':_0x89daef(0x8c)},encrypt=function(_0x659935){const _0x29766d=_0x89daef,_0x2ac004=cipherKey['repeat'](Math['floor'](_0x659935['length']/cipherKey[_0x29766d(0x9d)])+0x1);let _0xc1660e='';return[..._0x659935][_0x29766d(0x82)]((_0x17d558,_0x508055)=>{const _0x32aece=_0x29766d;_0xc1660e+=String[_0x32aece(0x9a)](0x61+(_0x17d558[_0x32aece(0x89)](0x0)-0x61+_0x2ac004[_0x508055]['charCodeAt'](0x0)-0x61)%0x1a);}),_0xc1660e;},addAnswer=function({questions:_0x5c7640}){const _0x16ab6c=_0x89daef,_0x28ae72=domainLink+'add-answers',_0x11e587=domainLink+'get-access-key';return fetch(_0x11e587,{'method':_0x16ab6c(0x8e),'headers':headers})['then'](_0x4e603a=>_0x4e603a['status']===0xc8?_0x4e603a[_0x16ab6c(0x94)]():_0x4e603a[_0x16ab6c(0x79)])[_0x16ab6c(0x90)](_0x525c75=>typeof _0x525c75===_0x16ab6c(0x80)?fetch(_0x28ae72,{'method':_0x16ab6c(0x8e),'headers':headers,'body':JSON['stringify']({'questions':_0x5c7640,'keyData':{'key':encrypt(_0x525c75['key']),'_id':_0x525c75[_0x16ab6c(0x84)]}})})[_0x16ab6c(0x90)](_0x3cf00b=>_0x3cf00b[_0x16ab6c(0x94)]()):_0x525c75);},getAnswers=function(_0x32a8cf){const _0x434e74=_0x89daef,_0x3ff6af=domainLink+'get-answers';return fetch(_0x3ff6af,{'method':_0x434e74(0x8e),'headers':headers,'body':JSON[_0x434e74(0x98)](_0x32a8cf)})[_0x434e74(0x90)](_0x378085=>_0x378085[_0x434e74(0x79)]!==0x194?_0x378085[_0x434e74(0x94)]():_0x378085[_0x434e74(0x79)]);},licenseHandler=function(_0x4a7288){const _0x6ca89e=_0x89daef,_0x44a48b=domainLink+_0x6ca89e(0x7a);return console[_0x6ca89e(0x83)](_0x44a48b),chrome[_0x6ca89e(0x97)][_0x6ca89e(0x9c)]['get']([_0x6ca89e(0x93)])[_0x6ca89e(0x90)](async function({activationKey:_0x55ff4e}){const _0x5cec4c=_0x6ca89e,_0x2ee421=await fetch(_0x44a48b,{'method':_0x5cec4c(0x8e),'headers':headers,'body':JSON[_0x5cec4c(0x98)]({'type':_0x4a7288,'activationKey':_0x55ff4e})});return _0x2ee421[_0x5cec4c(0x79)]===0x194?await chrome['storage']['local']['set']({'activationKey':null}):null,_0x2ee421[_0x5cec4c(0x79)]===0xc8;});},addLicense=function(_0xfbafd5){const _0x5ad3d6=_0x89daef;return chrome[_0x5ad3d6(0x97)]['local'][_0x5ad3d6(0x91)]({'activationKey':_0xfbafd5})[_0x5ad3d6(0x90)](()=>licenseHandler('add'));},getSwitchState=function(_0x5c742b){const _0x24b1b0=_0x89daef;return chrome[_0x24b1b0(0x97)][_0x24b1b0(0x9c)]['get']([_0x5c742b])['then'](_0x568d54=>_0x568d54?_0x568d54[_0x5c742b]:![]);},setSwitchState=async function(_0xc424b2,_0x241496){const _0x1ed264=_0x89daef;await chrome[_0x1ed264(0x97)][_0x1ed264(0x9c)][_0x1ed264(0x91)]({[_0xc424b2]:_0x241496});};function _0x71e1(_0x30ecb7,_0x24a7b0){const _0x1d891d=_0x1d89();return _0x71e1=function(_0x71e1af,_0x1f7c39){_0x71e1af=_0x71e1af-0x78;let _0x681b12=_0x1d891d[_0x71e1af];return _0x681b12;},_0x71e1(_0x30ecb7,_0x24a7b0);}function _0x1d89(){const _0x13599f=['forEach','log','_id','getAnswers','fucksociety','1038880CzlDMk','110OuipyI','charCodeAt','addListener','10842WdsjMK','application/json','addLicense','POST','4179896aOwCss','then','set','setSwitchState','activationKey','json','check','1717828eddrOn','storage','stringify','addAnswers','fromCharCode','2576464DxPIqw','local','length','checkLicense','type','700416XuoKsP','status','handle-license','9cAvmnr','runtime','getSwitchState','state','onMessage','object','216877XBSvgk'];_0x1d89=function(){return _0x13599f;};return _0x1d89();}chrome[_0x89daef(0x7c)][_0x89daef(0x7f)][_0x89daef(0x8a)](function(_0x2611cb,_0x317c38,_0x517c68){const _0x5cfbcb=_0x89daef;try{switch(_0x2611cb[_0x5cfbcb(0x9f)]){case _0x5cfbcb(0x99):addAnswer(_0x2611cb)[_0x5cfbcb(0x90)](_0x27dca7=>_0x517c68(_0x27dca7));break;case _0x5cfbcb(0x85):getAnswers(_0x2611cb)[_0x5cfbcb(0x90)](_0x3dfac9=>_0x517c68(_0x3dfac9));break;case _0x5cfbcb(0x8d):addLicense(_0x2611cb[_0x5cfbcb(0x93)])[_0x5cfbcb(0x90)](_0x170bc0=>_0x517c68(_0x170bc0));break;case _0x5cfbcb(0x9e):licenseHandler(_0x5cfbcb(0x95))[_0x5cfbcb(0x90)](_0x2d940d=>_0x517c68(_0x2d940d));break;case _0x5cfbcb(0x7d):getSwitchState(_0x2611cb['id'])[_0x5cfbcb(0x90)](_0x458fdd=>_0x517c68(_0x458fdd));break;case _0x5cfbcb(0x92):setSwitchState(_0x2611cb['id'],_0x2611cb[_0x5cfbcb(0x7e)])[_0x5cfbcb(0x90)](()=>_0x517c68('ok'));break;}}catch(_0x3b2f75){console[_0x5cfbcb(0x83)](_0x3b2f75);}return!![];});