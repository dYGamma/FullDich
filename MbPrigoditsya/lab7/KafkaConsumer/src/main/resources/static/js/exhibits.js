var app = angular.module('exhibits', []).config(function ($httpProvider) {
    csrftoken = $("meta[name='_csrf']").attr("content");
    csrfheader = $("meta[name='_csrf_header']").attr("content");
    $httpProvider.defaults.headers.common["X-CSRF-TOKEN"] = csrftoken;
    $(document).ajaxSend(function(e, xhr, options) {
        xhr.setRequestHeader(csrfheader, csrftoken);
    });
});

app.controller("ExhibitsController", function ($scope, $http) {

    $scope.successGetExhibitsCallback = function (response) {
        $scope.exhibitsList = response.data;
        $scope.errormessage="";
    };

    $scope.errorGetExhibitCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to get list of obj_list";
    };

    $scope.getExhibits = function () {
        $http.get('/exhibit').then($scope.successGetExhibitsCallback, $scope.errorGetExhibitCallback);
    };

    $scope.successDeleteExhibitCallback = function (response) {
        for (var i = 0; i < $scope.exhibitsList.length; i++) {
            var j = $scope.exhibitsList[i];
            if (j.id === $scope.deletedId) {
                $scope.exhibitsList.splice(i, 1);
                break;
            }
        }
        $scope.errormessage="";
    };

    $scope.errorDeleteExhibitCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to delete exhibit; check if there are any related records exist. Such records should be removed first";
    };

    $scope.deleteExhibit = function (id) {
        $scope.deletedId = id;
        $http.delete('/exhibit/' + id).then($scope.successDeleteExhibitCallback, $scope.errorDeleteExhibitCallback);
    };


    $scope.successGetExhibitCallback = function (response) {
        $scope.exhibitsList.splice(0, 0, response.data);
        $scope.errormessage="";
    };

    $scope.errorGetExhibitCallback = function (error) {
        console.log(error);
        $scope.errormessage="Unable to get information";
    };

    $scope.successAddExhibitCallback = function (response) {
        $http.get('/exhibit/' + $scope.response.id).then($scope.successGetExhibitCallback, $scope.errorGetExhibitCallback);
        $scope.errormessage="";
    };

    $scope.errorAddExhibitCallback = function (error) {
        console.log(error);
        $scope.errormessage="Impossible to add new exhibit; check if it's number is unique";
    };

    $scope.addExhibit = function (exhibit)
    {

        $scope.response={};
        $http.post('/exhibit', exhibit).then(function success (response) {
                $scope.response=response.data;

                $scope.successAddExhibitCallback();
                //$scope.getExhibits();
        });
    }

});
