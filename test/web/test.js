<!DOCTYPE html>
<head>
    <title>视频测试</title>
    <meta charset="utf-8">
    <script src="js\/jquery.min.js">
    </script>
</head>
<body>
    <div>该例子 在支持html的video标签的前提下，还要支持Navigator.getUserMedia(标准，各个浏览器接口不同)前提下</div>
    <a href="https://developer.mozilla.org/en-US/docs/Web/API/Navigator.getUserMedia">MozillaAPI</a>
    <a href="http:\/\/mozilla.com.cn\/post\/45435\/">参见例子</a>
    <br/>
    <video id="video"></video>
     <canvas  id="canvas" width="500px" height="500px"></canvas>
     <input id="test"/>
     <button id="send">发送</button>
    <script>
         var title = 'memoryza';
        ;(function($) {
            $.video =  function(s) {
                var s = $.extend({
                        video: true,
                        audio: true,
                        goStream: goStream,
                        noStream: noStream,
                        callBack: null,
                        videoId: 'video'
                    }, s),
                    video = $('#' + s.videoId),
                    canvas = $('#' + s.canvasId),
                    getUserMedia = (navigator.getUserMedia || navigator.webkitGetUserMedia || navigator.mozGetUserMedia || navigator.msGetUserMedia);
 
                if(!getUserMedia) {
                    alert('不支持');
                    return false;
                }
                 function noStream(err) {
                        if(err.PERMISSION_DENIED) {
                            alert('用户拒绝了浏览器请求媒体的权限');
                        } else if(err.NOT_SUPPORTED_ERROR) {
                            alert('constraint中指定的媒体类型不被支持');
                        } else if(err.MANDATORY_UNSATISFIED_ERROR) {
                            alert('指定的媒体类型未接收到媒体流');
                        }
                        console.log(err);
                }
                function goStream(stream) {
                    video[0].src = URL.createObjectURL(stream);
                    if(typeof s.callBack == 'function') {
                        s.callBack(video[0]);
                    }
                    stream.oninactive = noStream;
                }
                getUserMedia.call(navigator, {video: s.video, audio: s.audio}, s.goStream, s.noStream);
            }
 
        })(jQuery);
    </script>
    <script>
        function get_uuid() {
             var uuid = '';
            for (var i = 0; i < 32; i++) {
                uuid += Math.floor(Math.random() * 16).toString(16);
            }
            return uuid;
        }
        var uuid = get_uuid();
        $(function() {
            var canvas = document.getElementById('canvas');
            var ctx = canvas.getContext("2d");
            var a = webSocketFuc();
            $.video({callBack: function(video) {
                video.addEventListener('play', function(){
                    var $this = this;
                    setInterval(function() {
                        ctx.drawImage(video, 0, 0);
                        var image = canvas.toDataURL("image/png");
                        a.send(JSON.stringify({type: 'image', uuid: uuid, msg: image, }));
                    }, 500);
                },false);
                video.play();
 
            }});
            $(document).on('click','#send', function() {
                var msg = $('#test').val();
                a.send(JSON.stringify({'type': 'chat', msg: msg}));
 
            })
        })
 
    </script>
    <script>
        function webSocketFuc() {
            var canvas = document.getElementById('canvas');
            var ctx = canvas.getContext("2d");
            var wsServer = 'ws://192.168.1.100:8888',
                wss = new WebSocket(wsServer);
                wss.binaryType = "arraybuffer";
                wss.onopen = function() {
                     console.log('open');
                }
 
                wss.onclose = function() {
                    console.log('close');
                }
                /* 可以传送json和字符串还有二进制数据 */
                wss.onmessage = function(ev) {
                    //video.src = URL.createObjectURL(data);
                    var json_arr = JSON.parse(ev.data);
                    if(json_arr.type == 'image' ) {
                        if(json_arr.uuid != uuid) {
                            var image = new Image();
                            image.src = json_arr.msg;
                            image.onload = function() {
                                ctx.drawImage(image, 100, 83);
                            }
                        }
                    } else {
                        console.log(json_arr.msg);
                    }
                }
                wss.onerror = function(err) {
                     console.log(err);
                }
            return wss;
        }
    </script>
</body>
</html>