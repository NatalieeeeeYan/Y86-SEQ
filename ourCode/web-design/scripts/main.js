$(function(){
    var $pc=$('#pc');
    var $zf=$('#zf');
    var $sf=$('#sf');
    var $of=$('#of');
    var $rax=$('#rax');
    var $rcx=$('#rcx');
    var $rdx=$('#rdx');
    var $rbx=$('#rbx');
    var $rsp=$('#rsp');
    var $rbp=$('#rbp');
    var $rsi=$('#rsi');
    var $rdi=$('#rdi');
    var $r8=$('#r8');
    var $r9=$('#r9');
    var $r10=$('#r10');
    var $r11=$('#r11');
    var $r12=$('#r12');
    var $r13=$('#r13');
    var $r14=$('#r14');
    var $stat=$('#stat');
    var $mem=$('.mem');
    var pause=1000;
    $.ajax({
        type:'GET',
        url:'answer.json',
        dataType:"json",
        success:function(datas){
            console.log(datas);
            function startcpu(){
                var i=0;
                interval=setInterval(function(){
                    $pc.empty();
                    $zf.empty();
                    $sf.empty();
                    $of.empty();
                    $rax.empty();
                    $rcx.empty();
                    $rdx.empty();
                    $rbx.empty();
                    $rsp.empty();
                    $rbp.empty();
                    $rsi.empty();
                    $rdi.empty();
                    $r8.empty();
                    $r9.empty();
                    $r10.empty();
                    $r11.empty();
                    $r12.empty();
                    $r13.empty();
                    $r14.empty();
                    $stat.empty();
                    $mem.empty();
                    $pc.append(datas[i].PC);
                    $zf.append(datas[i].CC.ZF);
                    $sf.append(datas[i].CC.SF);
                    $of.append(datas[i].CC.OF);
                    $rax.append(datas[i].REG.rax);
                    $rcx.append(datas[i].REG.rcx);
                    $rdx.append(datas[i].REG.rdx);
                    $rbx.append(datas[i].REG.rbx);
                    $rsp.append(datas[i].REG.rsp);
                    $rbp.append(datas[i].REG.rbp);
                    $rsi.append(datas[i].REG.rsi);
                    $rdi.append(datas[i].REG.rdi);
                    $r8.append(datas[i].REG.r8);
                    $r9.append(datas[i].REG.r9);
                    $r10.append(datas[i].REG.r10);
                    $r11.append(datas[i].REG.r11);
                    $r12.append(datas[i].REG.r12);
                    $r13.append(datas[i].REG.r13);
                    $r14.append(datas[i].REG.r14);
                    $stat.append(datas[i].STAT);
                    var count =Object.keys(datas[i].MEM);
                    console.log(count);
                    for(var j in datas[i].MEM){
                        $mem.append('<li>'+j+': '+datas[i].MEM[j]+'</li>');
                    }
                    i++;
                    if(i>=datas.length) clearInterval(interval);
                },pause);
            }
            $('#button').on('click',function(){
                startcpu();
            });
        }
    });
});
